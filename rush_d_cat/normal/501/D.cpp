#include <iostream>
#include <cstring>
using namespace std;
const int NICO = 200000+10;
int n, a[NICO];
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int add)
{
    while(x <= NICO)
    {
        a[x] += add;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int res = 0;
    while(x!=0)
    {
        res += a[x];
        x -= lowbit(x);
    }
    return res;
}



int ka[NICO], kb[NICO];
int va[NICO], vb[NICO];
int a_plus_b[NICO];

void debug() {
    for(int i=1;i<=n;i++) {
        printf("%d ", ka[n-i+1]);
    }

    printf("\n");
    for(int i=1;i<=n;i++) {
        printf("%d ", kb[n-i+1]);
    }
    printf("\n");

    for(int i=1;i<=n;i++) {
        printf("%d ", a_plus_b[n-i+1]);
    }
    printf("\n");
}

int cac(int x) {
    int L = 1, R = n;

    while(R - L > 1) {
        int mid = (L+R)>>1;
        if(sum(mid) >= (x+1)) {
            R = mid;
        } else {
            L = mid;
        }
    }

    if(sum(L) >= (x+1)) R = L;

    return R - 1;
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &va[i]); va[i] ++;
        add(i, 1);
    }
    for(int i=1;i<=n;i++) {
        ka[n-i+1] = sum(va[i]-1); add(va[i], -1);
    }


    memset(a, 0, sizeof(a));

    for(int i=1;i<=n;i++) {
        scanf("%d", &vb[i]); vb[i] ++;
        add(i, 1);
    }

    for(int i=1;i<=n;i++) { 
        kb[n-i+1] = sum(vb[i]-1); add(vb[i], -1);
    }


    for(int i=1;i<=n;i++) {
        a_plus_b[i] = (ka[i] + kb[i]);
    }

    for(int i=1;i<=n;i++) {
        if(a_plus_b[i] > i-1) {
            a_plus_b[i] -= i;
            a_plus_b[i+1] ++;
        }
    }

    a_plus_b[n] %= n;


    //debug();

    memset(a, 0, sizeof(a));
    for(int i=1;i<=n;i++) add(i, 1);

    //printf("%d %d %d %d\n", sum(1), sum(2), sum(3), sum(4));
    for(int i=n;i>=1;i--) {
        int pos = cac(a_plus_b[i]); 
        //cout << a_plus_b[i] << " : " << pos << endl;
        //cout << "pos: " << pos << endl;
        add(pos+1, -1); 
        //cout << "add" << (pos+1) << endl;
        printf("%d ", pos);
    }
    printf("\n");
}