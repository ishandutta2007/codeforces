#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
using namespace std;

i64 A, B, i, j;
i64 Maxinum = 0x9FFFFFFFFFFFFFFFll;
i64 Subans, Major, Minor, Majc, Minc;

i64 Stru(int Pa, int Pb)
{
    i64 Subans = 0;
    Subans += (A - Pa + 1) * (A - Pa + 1);
    Subans += Pa - 1;
    Minor = B / Pb;
    Major = Minor + 1;
    Majc = B % Pb;
    Minc = Pb - Majc;
    Subans -= Minor * Minor * Minc;
    Subans -= Major * Major * Majc;
    return Subans;
}

void Struwithoutput(int Pa, int Pb)
{
    i64 Subans = 0;
    Subans += (A - Pa + 1) * (A - Pa + 1);
    Subans += Pa - 1;
    Minor = B / Pb;
    Major = Minor + 1;
    Majc = B % Pb;
    Minc = Pb - Majc;
    Subans -= Minor * Minor * Minc;
    Subans -= Major * Major * Majc;
    if (Subans != Maxinum) return;
    int i, j;
    if (Pa >= Pb)
        {   
            fortodo(i, 1, (A - Pa + 1)) printf("o");
            fortodo(i, 1, Pb)
                {
                    fortodo(j, 1, Minor) printf("x");
                    if (i <= Majc) printf("x");
                    if (i < Pa) printf("o");
                }
            printf("\n");
        }
    else
        {
            fortodo(i, 1, Pb)
                {
                    fortodo(j, 1, Minor) printf("x");
                    if (i <= Majc) printf("x");
                    if (i == 1)
                        fortodo(j, 1, (A - Pa + 1)) printf("o");
                    else
                        if (i < Pb)
                            printf("o");
                }
            printf("\n");
        }   
    exit(0);
}

int main()
{
    cin >> A >> B;
    if (A == 0)
        {
            cout << -B*B << endl;
            fortodo(i, 1, B) printf("x");
            printf("\n");
            return 0;
        }
    if (B == 0)
        {
            cout << A*A << endl;
            fortodo(i, 1, A) printf("o");
            printf("\n");
            return 0;
        }
    // oxox
    int P = min(A, B);
    fortodo(i, 1, P) Maxinum = max(Maxinum, Stru(i, i));
    P = min(A - 1, B);
    fortodo(i, 1, P) Maxinum = max(Maxinum, Stru(i + 1, i));
    P = min(A, B - 1);
    fortodo(i, 1, P) Maxinum = max(Maxinum, Stru(i, i + 1));
    //
    cout << Maxinum << endl;
    P = min(A, B);
    fortodo(i, 1, P) Struwithoutput(i, i);
    P = min(A - 1, B);
    fortodo(i, 1, P) Struwithoutput(i + 1, i);
    P = min(A, B - 1);
    fortodo(i, 1, P) Struwithoutput(i, i + 1);  
};