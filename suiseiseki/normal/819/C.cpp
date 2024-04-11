#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 1000000
#define ll long long
struct Each_prime{
	int pri,num;
	friend bool operator <(Each_prime p,Each_prime q){
		return p.pri<q.pri;
	}
}a[3][35];
int len[3];
int l[3][Maxn+5];
void work(int x,int num){
	for(int i=2;i*i<=num;i++){
		if(num%i==0){
			if(l[x][i]>0){
				while(num%i==0){
					a[x][l[x][i]].num++;
					num/=i;
				}
			}
			else{
				a[x][++len[x]].pri=i;
				a[x][len[x]].num=0;
				l[x][i]=len[x];
				while(num%i==0){
					a[x][l[x][i]].num++;
					num/=i;
				}
			}
		}
	}
	if(num>1){
		if(l[x][num]>0){
			a[x][l[x][num]].num++;
		}
		else{
			a[x][++len[x]].pri=num;
			a[x][len[x]].num=1;
			l[x][num]=len[x];
		}
	}
}
ll n,m,s;
ll ans;
void dfs_1(int x,ll sum){
	if(sum>n){
		return;
	}
	if(x>len[2]){
		ans++;
		return;
	}
	dfs_1(x+1,sum);
	for(int i=1;i<=a[2][x].num;i++){
		sum*=a[2][x].pri;
		dfs_1(x+1,sum);
	}
}
void dfs_2(int x,ll y,int z){
	if(y==0){
		return;
	}
	if(x>len[1]){
		ans+=y*z;
		return;
	}
	dfs_2(x+1,y,z);
	for(int i=0;i<=a[1][x].num;i++){
		y/=a[1][x].pri;
	}
	dfs_2(x+1,y,-z);
}
int main(){
	int t;
	scanf("%d",&t);
	int n_1,n_2,n_3;
	int m_1,m_2,m_3;
	int s_1,s_2,s_3;
	int i,j;
	while(t--){
		ans=0;
		memset(a,0,sizeof a);
		memset(len,0,sizeof len);
		memset(l,0,sizeof l);
		scanf("%d%d%d",&n_1,&n_2,&n_3);
		scanf("%d%d%d",&m_1,&m_2,&m_3);
		scanf("%d%d%d",&s_1,&s_2,&s_3);
		n=(ll)n_1*n_2*n_3;
		m=(ll)m_1*m_2*m_3;
		s=(ll)s_1*s_2*s_3;
		work(0,n_1);
		work(0,n_2);
		work(0,n_3);
		work(2,s_1<<1);
		work(2,s_2);
		work(2,s_3);
		for(int k=0;k<3;k++){
			sort(a[k]+1,a[k]+1+len[k]);
		}
		dfs_1(1,1);
		i=j=1;
		while(i<=len[0]&&j<=len[2]){
			if(a[0][i].pri==a[2][j].pri){
				if(a[0][i].num>a[2][j].num){
					a[1][++len[1]].pri=a[0][i].pri;
					a[1][len[1]].num=a[2][j].num;
				}
				i++;
				j++;
			}
			else if(a[0][i].pri<a[2][j].pri){
				a[1][++len[1]].pri=a[0][i].pri;
				a[1][len[1]].num=0;
				i++;
				continue;
			}
			else{
				j++;
			}
		}
		while(i<=len[0]){
			a[1][++len[1]].pri=a[0][i].pri;
			a[1][len[1]].num=0;
			i++;
		}
		dfs_2(1,m,1);
		cout<<ans<<endl;
	}
	return 0;
}