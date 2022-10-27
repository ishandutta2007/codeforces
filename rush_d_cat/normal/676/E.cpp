#include <iostream>
using namespace std;
typedef long long LL;

int n, k, cnt = 0;
int a[100000+10], known[100000+10];

int main() {
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n+1;i++) {
        char buf[20];
        scanf("%s", buf);
        if(*buf == '?') {
            known[i] = false; cnt ++;
        } else {
            known[i] = true; 
            sscanf(buf, "%d", &a[i]);
        }
    }

    int ok = 0;
        
    if(k == 0) {
        if(known[1] == 1 && a[1] == 0) ok = 1;
        if(known[1] == 0 && (n+1-cnt) % 2 == 1) ok = 1;
    } else {
        if(cnt != 0)
            ok = ( ( (n+1-cnt)%2 + cnt%2) % 2 ) == 0;
        
        int all_zero = n+1;
        while(a[all_zero] == 0) all_zero --;
        LL tmp = 0;
        if(cnt == 0) {
            for(int i=1;i<=n+1;i++) {
                tmp -= a[i];

                if(tmp % k != 0) break;
                if(i > all_zero && tmp != 0) break;
                //if(tmp == 0 && i == n) break;
                tmp /= k; 
                if(i==n+1 && tmp == 0) ok = 1;
            }

        }
    }
    printf("%s\n", ok?"Yes":"No");
}