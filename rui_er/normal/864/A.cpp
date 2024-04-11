#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int num[2];
	int cnt[2] = {0, 0};
	int a;
	bool have[2] = {false, false};
	for(int i=0;i<n;i++) 
	{
		cin>>a;
		if(!have[0])
		{
			have[0] = true;
			num[0] = a;
			cnt[0]++;
		}
		else if(a == num[0]) cnt[0]++;
		else if(!have[1])
		{
			have[1] = true;
			num[1] = a;
			cnt[1]++;
		}
		else if(a == num[1]) cnt[1]++;
		else
		{
			cout<<"NO"<<endl;
			goto end;
		}
	}
	if(cnt[0] == cnt[1]) cout<<"YES"<<endl<<num[0]<<" "<<num[1]<<endl;
	else cout<<"NO"<<endl;
	end: return 0;
}