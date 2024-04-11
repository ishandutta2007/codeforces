#include <iostream>
using namespace std;

bool sorted(int n, int *a){
    for(int i = 0; i < n - 1; i++){
        if(a[i] > a[i + 1]) return false;
    }
    return true;
}

int solve(){
    int n, x;
    cin >> n >> x;
    int a[502];
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    while(true){
        if(sorted(n, a)) return ans;
        int l = -1;
        for(int i = 0; i < n; i++){
            if(a[i] > x && (l == -1 || a[i] < a[l])) l = i;
        }
        if(l == -1) return -1;
        for(int i = l; i < n; i++){
            if(a[i] < x) return -1;
        }
        int r = -1;
        for(int i = 0; i < l; i++){
            if(a[i] > x){
                if(r == -1) r = i;
                else return -1;
            }
        }
        if(r != -1){
            swap(a[r], x);
            ans++;
            continue;
        }
        if(!sorted(l, a)) return -1;
        if(!sorted(n - l, a + l)){
            swap(a[l], x);
            ans++;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}