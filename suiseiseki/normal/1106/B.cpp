#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 100000
int a[Maxn+5];
int c[Maxn+5];
map<pair<int,int>,int> mp;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		mp[make_pair(c[i],i)]=a[i];
	}
	int t,num;
	pair<int,int> now;
	map<pair<int,int>,int>::iterator it,it_2;
	ll ans;
	while(m--){
		scanf("%d%d",&t,&num);
		now=make_pair(c[t],t);
		ans=0;
		if(mp.count(now)>0){
			if(mp[now]>=num){
				mp[now]-=num;
				ans=(ll)num*c[t];
				if(mp[now]==0){
					mp.erase(mp.find(now));
				}
			}
			else{
				ans=(ll)mp[now]*c[t];
				num-=mp[now];
				mp.erase(mp.find(now));
				it=mp.begin();
				while(it!=mp.end()&&num>0){
					if((it->second)>=num){
						ans+=(ll)num*(it->first).first;
						(it->second)-=num;
						num=0;
						if((it->second)==0){
							it_2=it;
							it++;
							mp.erase(it_2);
						}
						else{
							it++;
						}
					}
					else{
						ans+=(ll)(it->first).first*(it->second);
						num-=(it->second);
						it_2=it;
						it++;
						mp.erase(it_2);
					}
				}
				if(num>0){
					ans=0;
				}
			}
		}
		else{
			it=mp.begin();
			while(it!=mp.end()&&num>0){
				if((it->second)>=num){
					ans+=(ll)num*(it->first).first;
					(it->second)-=num;
					num=0;
					if((it->second)==0){
						it_2=it;
						it++;
						mp.erase(it_2);
					}
						else{
						it++;
					}
				}
				else{
					ans+=(ll)(it->first).first*(it->second);
					num-=(it->second);
					it_2=it;
					it++;
					mp.erase(it_2);
				}
			}
			if(num>0){
				ans=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}