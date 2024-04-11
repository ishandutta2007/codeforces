#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t, n, k;
string ans;
void upd(string s){
	if(s=="gougoushishabi"||s.size()>ans.size()) return;
	if(s.size()<ans.size()){
		ans=s; return;
	}
	for(int i=0;s[i];i++){
		if(s[i]>ans[i])return;
		if(s[i]<ans[i]){
			ans=s; return;
		}
	}
}
string cal(int las,int len) {
	int cnt=0; 
	if(las+k<10)cnt=0;
	else{
		cnt=len+1;
	}
	int need=n;
	need+=cnt*9*(las+k-9); 
	if(need<0)return "gougoushishabi";
	//printf("cnt=%d, need=%d\n", cnt, need);
	// (k+1)*s + k*(k+1)/2 = need
	int s=las+len*9;
	int add=0;
	while(1) {
		if(s*(k+1)+k*(k+1)/2 == need){
			//printf("# %d\n", add);
			string pre="";
			if(add>=9) {
				pre="8"; add-=8;
			}
			while(add){
				if(add>=9) pre="9"+pre, add-=9;
				else if(add) {
					pre=(char)(add+'0')+pre, add=0;
				}
			}
			for(int i=1;i<=len;i++) pre+="9";
			pre+=(char)('0'+las);
			return pre;
		}
		if(s*(k+1)+k*(k+1)/2 > need) return "gougoushishabi";
		add++; s++;
	}
	return "gougoushishabi";
}

int count(int x) {
	int ans = 0;
	while(x) ans += x % 10, x /= 10;
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d",&n,&k);
		ans=""; for(int i=0;i<100;i++)ans+="9";
		//cout<<cal(7,1)<<endl; return 0;
		for(int i=0;i<=9;i++){
			for(int j=0;j<=20;j++){
				upd(cal(i, j));
				// cout << i << " " << j << " " << cal(i, j) << endl;
			}
		}
		if(ans.size()==100) cout<<-1<<endl;
		else cout<<ans<<endl;
	
		/*
		int res=-1;
		for(int i=0;i<=1000;i++){
			int tmp=0;
			for(int j=i;j<=i+k;j++)tmp+=count(j);
			if(tmp==n) {
				res=i; break;
			}
		}
		cout << res << endl;
		*/
	}
}

/*
s, s+1, s+2, ..., s+k
(k+1)*s + k*(k+1)/2

4,5,6,7,8,9,10,11
*/