#include <iostream>
#include <vector>
using namespace std;
const int N = 200000 + 10;
int n,a[N];
int abs(int x) {
    if (x<0) return -x;
    return x;
}
vector<int> vec;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
    }

    int zero = 0, A = 0, B = 0;
    for(int i=1;i<=n;i++) {
        if(a[i] == 0) {
            zero ++; vec.push_back(i);
        }
        if(a[i] > 0) A ++;
        if(a[i] < 0) B ++;
    }
    int cnt = 0;
    if (zero >= 2) {


        int pos_ = 0, pos0 = 0, mx = 1e9+7, cnt = 0;
        
        if (B%2==1) {
            for(int i=1;i<=n;i++) {
                if(a[i]<0 && (-a[i])<mx) {
                    pos_=i; mx=-a[i];
                }
                if(a[i]==0) pos0=i;
            }
            ++ cnt;
            printf("1 %d %d\n", pos_, pos0);
        }

        for(int i=0;i<(int)vec.size()-1;i++) {
            printf("1 %d %d\n", vec[i], vec[i+1]); ++ cnt;
        }
        if (cnt == n-1) return 0;
        printf("2 %d\n", vec[(int)vec.size()-1]); ++ cnt;
        if (cnt == n-1) return 0;

        int rt = 0;
        for(int i=1;i<=n;i++) {
            if (a[i] && i!=pos_) rt = i;
        }
        if (rt == 0) return 0;
        for(int i=1;i<=n;i++) {
            if(a[i]!=0 && i!=rt && i!=pos_) {
                if(cnt==n-1) return 0;
                printf("1 %d %d\n", i, rt); ++ cnt;
            }
        }

        return 0;
    }

    if (zero == 1) {

        int pos_ = 0, pos0 = 0, mx = 1e9+7, cnt = 0;

 
        for(int i=1;i<=n;i++) {
            if(a[i]<0 && (-a[i])<mx) {
                pos_=i; mx=-a[i];
            }
            if(a[i]==0) pos0=i;
        }

        if(B%2==1) { 
            printf("1 %d %d\n", pos_, pos0); ++ cnt; if(cnt==n-1) return 0;
        } else {
            pos_ = 0;
        }

        int rt;
        for(int i=1;i<=n;i++) {
            if(a[i]) {
                rt = i;
            } 
        }

        printf("2 %d\n", pos0); ++ cnt; if(cnt==n-1) return 0;
        for(int i=1;i<=n;i++) {
            if (i!=rt && i!=pos0 && i!=pos_) {
                printf("1 %d %d\n", i, rt); ++cnt; if(cnt==n-1) return 0;
            }
        }

        return 0;
    }

    if (B%2==0) {
        for(int i=2;i<=n;i++) {
            printf("%d %d %d\n", 1, i, 1);
        }            
    } else {
        int bu = 1e9+7, bst = -1;
        for (int i=1;i<=n;i++) {
            if(a[i] < 0 && abs(a[i]) < bu) {
                bu = abs(a[i]); bst = i;
            }
        }
        printf("2 %d\n", bst);
        int rt;
        for(int i=1;i<=n;i++) {
            if(i!=bst) {
                rt = i;
            }
        }
        for(int i=1;i<=n;i++) {
            if(i!=rt && i!=bst) {
                printf("%d %d %d\n", 1, i, rt);
            }
        }
    }
}