#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

long long N;

int main()
{
    cin >> N;
    while (N % 3 == 0) N /= 3;
    N /= 3; N++;
    cout << N << endl;
    return 0;
};