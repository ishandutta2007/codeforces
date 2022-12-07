#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<memory.h>

using namespace std;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	string s1,s2;
	cin >> s1 >> s2;
	for (int i=0;i<s1.size();i++)if (s1[i]!=s2[i])putchar('1');else putchar('0');
	puts("");
	return 0;
}