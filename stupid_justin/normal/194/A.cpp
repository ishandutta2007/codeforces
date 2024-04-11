#include<bits/stdc++.h>
using namespace std;
int main()
{
	int grade,subject,ans;
	cin>>subject>>grade;
	ans=3*subject-grade;
	if (ans<0) cout<<"0"<<endl;else cout<<ans<<endl;
	return 0;
}