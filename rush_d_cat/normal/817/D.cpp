#include <iostream>
using namespace std;
typedef long long LL;
const int NICO = 1000002;
int n, a[NICO], cnt[NICO];
int premax[NICO], nxtmax[NICO];
int premin[NICO], nxtmin[NICO];
int st[NICO];
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        cnt[a[i]] ++;
    }

    int top;
    LL summax = 0, summin = 0; 
    
    top = 0;
    for(int i=1;i<=n;i++) {
        while(top > 0 && a[i] < a[st[top]]) {
            top --;
        }
        premin[i] = st[top];
        st[++top] = i;
    }

    top = 0;
    for(int i=1;i<=n;i++) {
        while(top > 0 && a[i] > a[st[top]]) {
            top --;
        }
        premax[i] = st[top];
        st[++top] = i;
    }

    st[0] = n+1;
    top = 0;
    for(int i=n;i>=1;i--) {
        while(top > 0 && a[i] <= a[st[top]]) {
            top --;
        }
        nxtmin[i] = st[top];
        st[++top] = i;        
    }

    top = 0;
    for(int i=n;i>=1;i--) {
        while(top > 0 && a[i] >= a[st[top]]) {
            top --;
        }
        nxtmax[i] = st[top];
        st[++top] = i;        
    }

    for(int i=1;i<=n;i++) {
        //printf("premin[%d] = %d, nxtmin[%d] = %d\n", i, premin[i], i, nxtmin[i]);
        //printf("premax[%d] = %d, nxtmax[%d] = %d\n", i, premax[i], i, nxtmax[i]);
        summax += (LL)(nxtmax[i] - i) * (i - premax[i]) * a[i];
        summin += (LL)(nxtmin[i] - i) * (i - premin[i]) * a[i]; 
    }

    cout << (summax - summin) << endl;
}