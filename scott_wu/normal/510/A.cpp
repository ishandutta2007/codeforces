#include<bits/stdc++.h>
using namespace std;

int main()
{
int N, M;
cin >> N >> M;
for (int i = 0; i < N; i++)
{
for (int j = 0; j < M; j++)
cout << ((i % 2 == 0 || j == (M - 1) * (1 - i / 2 % 2)) ? '#' : '.');
cout << '\n';
}
}