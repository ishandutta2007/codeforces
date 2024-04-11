#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

int n;
bool b[30];
int k;

unordered_map<int, int> M;
int a[300500], p[300500];

int get_small(int t){
    bool del = false;
    int k = 0;
    int s = 1;
    int res = 0;
    for(int i = 29; i >= 0; i--){b[k++] = (t%2); t/=2;}
    for(int i = 29; i >= 0; i--){
        if(b[i] == 1){
            if(M[s*2+1]-- > 0) s = s*2+1, res = res*2;
            else{
                M[s*2]--;
                s = s*2, res = res * 2 + 1;
            }
        }
        else{
            if(M[s*2]-- > 0) s = s*2, res = res*2;
            else{
                M[s*2+1]--;
                s = s*2+1 , res = res * 2 + 1;
            }
        }

    }
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    for(int i = 0; i < n; i++){
        k = 0;
        int pi = p[i];
        int s = 1;
        for(int i = 29; i >= 0; i--){
            b[k++] = (pi%2);
            pi/=2;
        }
        for(int i = 29; i >= 0; i--){
            s *= 2;
            s += b[i];

            M[s] ++;
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ", get_small(a[i]));
    }

}