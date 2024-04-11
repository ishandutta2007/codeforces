#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> ans;
		int pos=-1;
		for(int i=2;i<=n;i++){
			cout<<"? "<<1<<" "<<i-1<<"\n";
			cout<<i<<"\n";
			for(int j=1;j<i;j++) cout<<j<<" ";
			cout<<"\n";
			fflush(stdout);
			int x;cin>>x;
			if(x!=0){
				pos=i;break;
			}
		}
		int l=1,r=pos-1;
		while(l<=r){
			if(l==r) break;
			int mid=(l+r)/2;
			cout<<"? "<<1<<" "<<mid-l+1<<"\n";
			cout<<pos<<"\n";
			for(int i=l;i<=mid;i++) cout<<i<<" ";
			cout<<"\n";
			fflush(stdout);
			int x;cin>>x;
			if(x==0) l=mid+1;
			else r=mid;
		}
		for(int i=1;i<pos;i++) if(i!=l) ans.push_back(i);
		for(int i=pos+1;i<=n;i++){
			cout<<"? "<<1<<" "<<1<<"\n";
			cout<<pos<<"\n";
			cout<<i<<"\n";
			fflush(stdout);
			int x;cin>>x;
			if(x==0) ans.push_back(i);
		}
		cout<<"! "<<ans.size()<<" ";
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
		cout<<"\n";
		fflush(stdout);
	}
	return 0;
}