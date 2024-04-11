// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int K, M;
vector<int> B[10000];

void Att(vector<int> &a, vector<int> &b, vector<int> &c)
{
	for (vector<int>::iterator bit = b.begin(); bit != b.end(); bit++)
		for (vector<int>::iterator cit = c.begin(); cit != c.end(); cit++)
			{
				a.push_back(*bit + *cit);
				a.push_back(*bit * *cit);
			}
}

int main()
{
	scanf("%d%d", &K, &M);
	B[0].clear(); B[0].push_back(0);
	int i;
	fortodo(i, 1, 9999)
		{
			B[i].clear();
			B[i].push_back(-i);
			B[i].push_back(i);
			if (i / 10) Att(B[i], B[i / 10], B[i % 10]);
			if (i / 100) Att(B[i], B[i / 100], B[i % 100]);
			if (i / 1000) Att(B[i], B[i / 1000], B[i % 1000]);
			sort(B[i].begin(), B[i].end());
			B[i].resize(unique(B[i].begin(), B[i].end()) - B[i].begin());
		}
	fortodo(i, 0, 9999)
		for (vector<int>::iterator it = B[i].begin(); it != B[i].end(); it++)
			if ((K + *it >= 0) && (K + *it < 10000) && (M))
				{
					printf("%04d%04d\n", K + *it, i);
					M--;
				}
}