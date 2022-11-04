//a, b, c, d
//a serve, a break, b serve, b break
//a + b = A, c + d = B
//a - b = c - d
//
//a + b = A, c + d = B
//a - b + 1 = c - d
//
//
//let b + d = x;
//d = x - b;
//x >= b >= 0;
//a + b = A, c + x - b = B
//a = A - b, c = B + b - x;
//a + x - b = b + c
//2x = B - A + 4b


#include <cstdio>
#include <set>
using namespace std;

int t, A, B, a, b, c, d, tmp;
set<int> st;

int main(){
	scanf("%d", &t);
	while(t--){
		st.clear();
		scanf("%d%d", &A, &B);
		if((A + B) & 1){
			for(int a = 0; a <= A; a++){
				b = A - a;
				tmp = a - b + 1;
				if((B + tmp) % 2) continue;
				c = (B + tmp) / 2;
				d = (B - tmp) / 2;
				if(c >= 0 && d >= 0) st.insert(b + d);
			}
			for(int a = 0; a <= A; a++){
				b = A - a;
				tmp = a - b - 1;
				if((B + tmp) % 2) continue;
				c = (B + tmp) / 2;
				d = (B - tmp) / 2;
				if(c >= 0 && d >= 0) st.insert(b + d);
			}
		}else{
			for(int a = 0; a <= A; a++){
				b = A - a;
				tmp = a - b;
				if((B + tmp) % 2) continue;
				c = (B + tmp) / 2;
				d = (B - tmp) / 2;
				if(c >= 0 && d >= 0) st.insert(b + d);
			}
		}
		printf("%d\n", st.size());
		for(int x : st) printf("%d ", x);
		putchar('\n');
	}
	return 0;
}