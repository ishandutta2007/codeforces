#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
const int MAX=200005;
const int MOD=1000000000 + 7;
int x,mn,tmp;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>x;
	mn=6;
	rep(a,0,9){
		rep(b,0,9){
			rep(c,0,9){
				rep(d,0,9){
					rep(e,0,9){
						rep(f,0,9){
							if(a+b+c==d+e+f){
								tmp=0;
								if(x/100000!=a)tmp++;
								if((x%100000)/10000!=b)tmp++;
								if((x%10000)/1000!=c)tmp++;
								if((x%1000)/100!=d)tmp++;
								if((x%100)/10!=e)tmp++;
								if((x%10)!=f)tmp++;
								if(mn>tmp)mn=tmp;//,cout<<a<<b<<c<<d<<e<<f<<endl
							}
						}
					}
				}
			}
		}
	}
	cout<<mn<<endl;
	return 0;
}