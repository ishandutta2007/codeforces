#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int main()
{
    i64 N, M, A;
    cin >> N >> M >> A;
    cout << ((N + A - 1) / A) * ((M + A - 1) / A) << endl;
}