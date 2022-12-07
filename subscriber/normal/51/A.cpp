#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

char a[5];
string s[2222];
int n;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a[0] >> a[1] >> a[3] >> a[2];
		string s1="";
		string s2="";
		string s3="";
		string s4="";
		for (int j=0;j<4;j++)s1+=a[j%4];
		for (int j=1;j<5;j++)s2+=a[j%4];
		for (int j=2;j<6;j++)s3+=a[j%4];
		for (int j=3;j<7;j++)s4+=a[j%4];
		s[i]=min(min(s1,s2),min(s3,s4));
		cin >> a[0] >> a[0];
	}
	sort(s,s+n);
	int ans=1;
	for (int i=1;i<n;i++)if (s[i]!=s[i-1])ans++;
	cout << ans << endl;
	return 0;
}