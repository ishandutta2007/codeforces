// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

struct Order1
{
    double k, b;
    Order1(double k = 0, double b = 0)
    {
        this->k = k;
        this->b = b;
    }
    Order1 operator + (Order1 snd)
    {
        return Order1(k + snd.k, b + snd.b);
    }
    Order1 Offset(double delta)
    {
        return Order1(k, b - k * delta);
    }
    double point0()
    {
        return - b / k;
    }
    double valueAt(double x)
    {
        return k * x + b;
    }
};

#include<vector>

typedef pair<double,Order1> Section;
typedef vector<Section> Function;

double K[6010];
Function Derivate;

bool operator < (Section lhs, Section rhs)
{
    return lhs.first < rhs.first;
}

int N, Q, A, B;
int X[6010];

double Zeropoint(Function &f, double Right)
{
    double Border = Right;
    for (Function::reverse_iterator rit = f.rbegin(); rit != f.rend(); rit++)
        {
            double Z = rit->second.point0();
            if ((Z > rit->first - 1e-9) && (Z < Border + 1e-9))
                return Z;
            Border = rit->first;
        }
    for (Function::iterator it = f.begin(); it + 1 != f.end(); it++)
        if ((it->second.valueAt((it + 1)->first) < 1e-9) && ((it + 1)->second.valueAt((it + 1)->first) > -1e-9))
            return (it + 1)->first;
    if (f.back().second.valueAt(Right) < 0)
        return Right;
    else
        return f.front().first;
}

Section Insert(Function &f, double x)
{
    Function::iterator it;
    for (it = f.begin(); it != f.end(); it++)
        if (abs(x - it->first) < 1e-9)
            return *it;
    for (it = f.begin(); it != f.end(); it++)
        if (it->first > x)
            break;
    Section section = make_pair(x, (it - 1)->second);
    f.insert(it, section);
    return section;
}

int main()
{
    scanf("%d%d%d%d", &N, &Q, &A, &B);
    int i;
    fortodo(i, 1, N) scanf("%d", &X[i]);
    if (Q == 1)
        {
            fortodo(i, 1, N) printf("1%s", (i == N) ? "\n" : "");
            printf("0\n");
            return 0;
        }
    Derivate.clear();
    Derivate.push_back(make_pair(1, Order1(2, -2.0 * X[1])));
    fortodo(i, 1, N - 1)
        {
            K[i] = Zeropoint(Derivate, Q - (N - i) * A);
            //printf("K[%d] = %.10f\n", i, K[i]);
            Section k = Insert(Derivate, K[i]);
            Function::iterator mit = lower_bound(Derivate.begin(), Derivate.end(), k);
            //printf("mit = %.10f~\n", mit->first);
            for (Function::iterator it = Derivate.begin(); it != mit; it++)
                {
                    it->first += A;
                    it->second = it->second.Offset(A);
                }
            for (Function::iterator it = mit; it != Derivate.end(); it++)
                {
                    it->first += B;
                    it->second = it->second.Offset(B);
                }
            if (A != B) Derivate.insert(mit, make_pair(K[i] + A, Order1(0, 0)));
            Order1 att(2, -2.0 * X[i + 1]);
            for (Function::iterator it = Derivate.begin(); it != Derivate.end(); it++)
                it->second = it->second + att;
            while (Derivate.back().first > (Q - (N - 1 - i) * A) - 1e-9) Derivate.pop_back();
            /*          
            for (Function::iterator it = Derivate.begin(); it != Derivate.end(); it++)
                printf("%.10f(%.10f) ~ : %.10fx + %.10f\n", it->first, it->second.valueAt(it->first), it->second.k, it->second.b);      
            puts("");
            */
        }
    K[N] = Zeropoint(Derivate, Q);
    for (i = N - 1; i; i--)
        if (K[i + 1] > K[i] + B)
            K[i] = K[i + 1] - B;
        else
            if (K[i + 1] < K[i] + A)
                K[i] = K[i + 1] - A;
    double price = 0;
    fortodo(i, 1, N) price += pow(K[i] - X[i], 2);
    fortodo(i, 1, N) printf("%.12f%s", K[i], (i == N) ? "\n" : " ");
    printf("%.12f\n", price);
}