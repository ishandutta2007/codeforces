#include<cstdio>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;


int main(){
	int n, m, k, t, a, b, x, l, r, c;
	vector<int> v;
	
	scanf("%d%d%d%d",&n,&m,&k,&t);
	
	rep(i,k){
		scanf("%d%d",&a,&b);
		v.pb((a-1)*m+b);
	}
	
	sort(v.begin(),v.end());
	
	rep(i,t){
		scanf("%d%d",&a,&b);
		x = (a-1)*m+b;
		l = 0; r = v.size()-1;
		rep(i,100){
			c = (l+r)/2;
			if(v[c] < x){
				l = c+1;
			} else {
				if(v[c] == x){l = -1; break;}
				r = c;
			}
		}
		
		if(l == -1){
			puts("Waste");
		} else {
			switch((x-l)%3){
				case 0:
					puts("Grapes");
					break;
				case 1:
					puts("Carrots");
					break;
				case 2:
					puts("Kiwis");
					break;
			}
		}
	}
	
	return 0;
}

/*
#include<cstdio>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;


int main(){
	int x, y, t = 1, j;
	
	scanf("%d%d",&x,&y);
	
	while(y >= 2 && x*10+y >= 22){
		if(t){
			for(j = 0; j < 2 && x > j; j++);
			x -= j;
			y -= (2-j)*10+2;
		} else {
			for(j = 2; j < 22 && y >= j+10; j+=10);
			x -= (22-j)/10;
			y -= j;
		}
		t = (t+1)%2;
	}
	
	printf("%s\n",(t)?"Hanako":"Ciel");
	
	return 0;
}
*/