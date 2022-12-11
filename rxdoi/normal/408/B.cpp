#include<iostream>
#include<string>
using namespace std;

string A,B;
int cnt[27],cnt2[27],Ans=0,flag=0;

int main()
{
	cin>>A>>B;
	for (int i=0;i<A.length();i++) cnt[A[i]-'a']++;
	for (int i=0;i<B.length();i++) cnt2[B[i]-'a']++;
	for (int i='a';i<='z';i++) 
	{
		if (cnt2[i-'a']&&!cnt[i-'a']) flag=1;
		Ans+=min(cnt[i-'a'],cnt2[i-'a']);
	}
	if (!Ans||flag) Ans=-1;
	cout<<Ans<<endl;
	return 0;
}