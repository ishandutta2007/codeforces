#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100
struct String{
	char s[Maxn+5];
	int len;
	int id;
	int ans;
	void read(){
		scanf("%s",s+1);
		len=0;
		while(s[++len]!='\0');
		len--;
	}
	friend bool operator <(String p,String q){
		return p.len>q.len;
	}
}a[Maxn<<1|5];
bool cmp(String p,String q){
	return p.id<q.id;
}
int n;
int len;
bool work(){
	a[1].ans=0;
	a[2].ans=1;
	bool yes;
	for(int i=3;i<=len;i+=2){
		yes=1;
		if(a[i-2].ans==0){
			for(int j=1;j<=a[i].len;j++){
				if(a[i].s[j]!=a[i-2].s[j]){
					yes=0;
					break;
				}
			}
		}
		else{
			for(int j=1;j<=a[i].len;j++){
				if(a[i].s[j]!=a[i-2].s[j+1]){
					yes=0;
					break;
				}
			}
		}
		if(yes){
			a[i].ans=a[i-2].ans;
			a[i+1].ans=a[i-1].ans;
			yes=1;
			if(a[i-1].ans==0){
				for(int j=1;j<=a[i+1].len;j++){
					if(a[i+1].s[j]!=a[i-1].s[j]){
						yes=0;
						break;
					}
				}
			}
			else{
				for(int j=1;j<=a[i+1].len;j++){
					if(a[i+1].s[j]!=a[i-1].s[j+1]){
						yes=0;
						break;
					}
				}
			}
			if(!yes){
				return 0;
			}
		}
		else{
			a[i].ans=a[i-1].ans;
			a[i+1].ans=a[i-2].ans;
			yes=1;
			if(a[i-1].ans==0){
				for(int j=1;j<=a[i].len;j++){
					if(a[i].s[j]!=a[i-1].s[j]){
						yes=0;
						break;
					}
				}
			}
			else{
				for(int j=1;j<=a[i].len;j++){
					if(a[i].s[j]!=a[i-1].s[j+1]){
						yes=0;
						break;
					}
				}
			}
			if(!yes){
				return 0;
			}
			yes=1;
			if(a[i-2].ans==0){
				for(int j=1;j<=a[i+1].len;j++){
					if(a[i+1].s[j]!=a[i-2].s[j]){
						yes=0;
						break;
					}
				}
			}
			else{
				for(int j=1;j<=a[i+1].len;j++){
					if(a[i+1].s[j]!=a[i-2].s[j+1]){
						yes=0;
						break;
					}
				}
			}
			if(!yes){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	len=(n<<1)-2;
	for(int i=1;i<=len;i++){
		a[i].read();
		a[i].id=i;
	}
	sort(a+1,a+1+len);
	for(int i=1;i<n-1;i++){
		if(a[1].s[i+1]!=a[2].s[i]){
			swap(a[1],a[2]);
			break;
		}
	}
	if(!work()){
		swap(a[1],a[2]);
		work();
	}
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++){
		if(a[i].ans){
			putchar('S');
		}
		else{
			putchar('P');
		}
	}
	puts("");
	return 0;
}