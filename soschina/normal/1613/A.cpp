#include <cstdio>
using namespace std;

int t, x1, p1, x2, p2, cnt1, cnt2;

int main(){
	scanf("%d", &t);
	while(t--){
		cnt1 = cnt2 = 0;
		scanf("%d%d%d%d", &x1, &p1, &x2, &p2);
		for(int i = x1; i; i /= 10)
			cnt1++;
		for(int i = x2; i; i /= 10)
			cnt2++;
		if(p1 + cnt1 != p2 + cnt2){
			printf("%c\n", p1 + cnt1 < p2 + cnt2 ? '<' : '>');
		}else{
			while(cnt1 < cnt2) x1 *= 10, cnt1++;
			while(cnt1 > cnt2) x2 *= 10, cnt2++;
			if(x1 != x2) printf("%c\n", x1 < x2 ? '<' : '>');
			else puts("=");
		}
	}
	return 0;
}