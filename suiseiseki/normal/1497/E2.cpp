#include <set>
#include <cstdio>
const int Maxk=20;
const int Maxn=200000;
const int Maxv=10000000;
const int Inf=0x3f3f3f3f;
int lst[Maxv+5];
int num_to_num[Maxv+5];
void init(){
	for(int i=1;i<=Maxv;i++){
		num_to_num[i]=i;
		lst[i]=-1;
	}
	for(int i=2;i*i<=Maxv;i++){
		for(int j=1;j*i*i<=Maxv;j++){
			num_to_num[j*i*i]=num_to_num[j];
		}
	}
}
int n,k;
int a[Maxn+5];
int f[Maxn+5][Maxk+5];
std::set<int> st;
void solve(){
	st.clear();
	scanf("%d%d",&n,&k);
	st.insert(-1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=num_to_num[a[i]];
		for(int j=0;j<=k;j++){
			f[i][j]=Inf;
		}
		if(lst[a[i]]!=-1){
			st.insert(lst[a[i]]);
		}
		lst[a[i]]=i;
		std::set<int>::iterator it=st.end();
		int num=-1;
		do{
			it--;
			num++;
			for(int j=0;j+num<=k;j++){
				f[i][j+num]=std::min(f[i][j+num],f[(*it)][j]+1);
			}
		}while(it!=st.begin()&&num<k);
	}
	int ans=Inf;
	for(int i=0;i<=k;i++){
		ans=std::min(ans,f[n][i]);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		lst[a[i]]=-1;
	}
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}