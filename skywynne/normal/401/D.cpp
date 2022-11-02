#include<bits/stdc++.h>
using namespace std;
int m, R[20];
long long n;
map < vector < int > , vector < long long > > M;
int Solve(vector < int > A, int c, int q)
{
    vector < int > B;
    vector < long long > C;
    for (int i = 0; i < 100; i++)
    {
        C.push_back(0);
    }
    for (int i = 0; i <= 9; i++)
    {
        B.push_back(A[i]);
    }
    for (int i = 0; i <= 9; i++)
    {
        if ((A[i] == 0) || (i == 0 && q == 1))
        {
            continue;
        }
        B[i] --;
        if (M.count(B) == 0)
        {
            Solve(B, c - 1, 0);
        }
        for (int j = 0; j < m; j++)
        {
            C[(j + i * R[c - 1]) % m] = C[(j + i * R[c - 1]) % m] + M[B][j];
        }
        B[i] ++;
    }
    M[A] = C;
    /*for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << C[i] << " ";
    }
    cout << "\n\n";*/
    return (0);
}
int main()
{
    cin >> n >> m;
    int c = 0;
    vector < int > A;
    vector < long long > B;
    for (int i = 0; i < 10; i++)
    {
        A.push_back(0);
    }
    B.push_back(1);
    for (int i = 1; i < 100; i++)
    {
        B.push_back(0);
    }
    M[A] = B;
    R[0] = 1 % m;
    for (int i = 1; i < 20; i++)
    {
        R[i] = (R[i - 1] * 10) % m;
    }
    while (n != 0)
    {
        A[n % 10] ++;
        n /= 10;
        c ++;
    }
    Solve(A, c, 1);
    cout << (M[A])[0];
    return (0);
}