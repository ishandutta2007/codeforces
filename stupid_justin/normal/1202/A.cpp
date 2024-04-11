#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int MOD=1e9+7;
const int inf=0x3f3f3f3f;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int len1=str1.length();
		int len2=str2.length();
		int t=0,k=0;
		for (int i=len2-1;i>=0;i--) 
		{
			if (str2[i]=='1') break;
			k++;
		}
//		printf("k=%d\n",k);
		//str21len2-k 		
		for (int i=len1-k-1;i>=0;i--) 
		{
			if (str1[i]=='1') break;
			t++;
		}
		cout<<t<<endl;
	}
	return 0;
}