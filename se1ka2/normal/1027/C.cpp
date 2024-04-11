#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int a[1000002];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        bool g = false;
        for(int i = 0; i < n - 3; i++){
            bool f = true;
            for(int j = i; j < i + 4; j++){
                if(a[j] != a[i]){
                    f = false;
                    break;
                }
            }
            if(f){
                for(int j = 0; j < 4; j++) cout << a[i] << " ";
                cout << endl;
                g = true;
                break;
            }
        }
        if(g) continue;
        a[n] = -1;
        int b[500002];
        int k = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == a[i + 1]){
                b[k] = a[i];
                k++;
                while(a[i] == a[i + 1]) i++;
            }
        }
        int l = 1;
        for(int i = 2; i < k; i++){
            if(b[i - 1] * b[l] > b[i] * b[l - 1]) l = i;
        }
        cout << b[l - 1] << " " << b[l - 1] << " " << b[l] << " " << b[l] << endl;
    }
}