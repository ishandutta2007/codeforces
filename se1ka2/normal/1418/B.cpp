#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[1002];
        for(int i = 0; i < n; i++) cin >> a[i];
        int l[1002];
        for(int i = 0; i < n; i++) cin >> l[i];
        int b[1002];
        int k = 0;
        for(int i = 0; i < n; i++){
            if(!l[i]) b[k++] = a[i];
        }
        sort(b, b + k);
        int x[1002];
        int j = 0;
        for(int i = 0; i < n; i++){
            if(!l[i]) x[i] = b[j++];
            else x[i] = a[i];
        }
        int c = 0;
        int s = 0;
        for(int i = 1; i <= n; i++){
            s += x[i - 1];
            if(s < 0) c = i;
        }
        int y[1002];
        for(int i = 0; i < n; i++){
            if(!l[i]) y[i] = b[--j];
            else y[i] = a[i];
        }
        s = 0;
        int d = 0;
        for(int i = 1; i <= n; i++){
            s += y[i - 1];
            if(s < 0) d = i;
        }
        if(c < d){
            for(int i = 0; i < n; i++) cout << x[i] << " ";
            cout << endl;
        }
        else{
            for(int i = 0; i < n; i++) cout << y[i] << " ";
            cout << endl;
        }
    }
}