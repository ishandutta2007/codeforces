#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;


typedef pair<int, int> P;

void printp(P a){
	int fst = a.first;
	int snd = a.second;
	for(int i = snd; i <= fst; i++){
		printf("%d ", i);
	}
}

queue<P> Q;

using namespace std;

int main() {
    int n,k;
    int maxk = 0;

    int mul2 = 0;
    scanf("%d%d",&n, &k);
    int tmpn = n;
    while(tmpn > 0) {
        tmpn /= 2;
        mul2 ++;
    }
    maxk = pow(2,mul2) - 1 + (n % (int)pow(2,mul2-1)) * 2;
    if(k > maxk || k % 2 == 0) {
        printf("-1");
    } else {
        int remain = k - 1;
        int len = 1;
        Q.push(P(n,1));
        while(true) {
            if(remain < len * 2) {
                //printf("remain = %d len = %d\n break", remain, len);
				break;
            }
            for(int i = 0; i < len; i++) {
            	
                P p = Q.front();
                Q.pop();
                //printf("%d %d\n", p.first, p.second);
                //system("pause");
                if(p.first == p.second) {
                    Q.push(p);
                    i--;
                    continue;
                }
                int mid = (p.first + p.second) / 2;
                
                Q.push(P(p.first, mid+1));
                Q.push(P(mid, p.second));
                //printf("pop %d %d, push %d,%d and %d %d\n", p.first, p.second,p.first, mid,mid-1, p.second);
            }
            remain -= len * 2;
            len *= 2;
        }
        //printf("remain = %d", remain);
//		
//		while(!Q.empty()){
//        	P p = Q.front();
//			Q.pop();
//			printp(p); 
//		}
        for(int i = 0; i < remain / 2; i++) {
            P p = Q.front();
            //printf("\n pop %d %d\n", p.first, p.second);
            Q.pop();
            if(p.first == p.second) {
                printp(p);
                i--;
                continue;
            }
            int mid = (p.first + p.second) / 2;
            //printf("mid = %d\n", mid); 
            printp(P(p.first, mid+1));
            printp(P(mid, p.second));
        }
        while(!Q.empty()){
        	P p = Q.front();
			Q.pop();
			printp(p);
		}
    }
    return 0;

}