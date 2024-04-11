#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[200005];
    int b[200005]{0};
    for(int i = 0; i < n; i++){
        cin >> x[i];
        b[x[i]]++;
    }
    int l = 0;
    for(int i = 1; i <= n; i++){
        if(b[i]){
            l++;
            i += 2;
        }
    }
    for(int i = 0; i <= n + 1; i++){
        if(i <= n && b[i] == 0 && b[i + 1] >= 1){
            b[i]++;
            b[i + 1]--;
        }
        if(i > 0 && b[i - 1] >= 2){
            b[i - 1]--;
            b[i]++;
        }
    }
    int r = 0;
    for(int i = 0; i <= n + 1; i++) if(b[i]) r++;
    cout << l << " " << r << endl;
}