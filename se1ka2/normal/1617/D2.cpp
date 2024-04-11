#include <iostream>
using namespace std;

void output(int i, int j, int k){
    cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool b[10004];
        int l = -1, r = -1;
        for(int i = 0; i < n / 3; i++){
            output(i * 3, i * 3 + 1, i * 3 + 2);
            cin >> b[i];
            if(i && b[i] != b[i - 1]){
                bool f;
                output(i * 3 - 2, i * 3 - 1, i * 3);
                cin >> f;
                if(f != b[i - 1]){
                    l = i * 3 - 3, r = i * 3;
                    break;
                }
                output(i * 3 - 1, i * 3, i * 3 + 1);
                cin >> f;
                if(f != b[i - 1]){
                    l = i * 3 - 2, r = i * 3 + 1;
                    break;
                }
                l = i * 3 - 1, r = i * 3 + 2;
                break;
            }
        }
        bool ans[10004];
        ans[l] = b[l / 3], ans[r] = b[r / 3];
        for(int i = l / 3 * 3; i < n; i++){
            if(i != l && i != r){
                output(l, r, i);
                cin >> ans[i];
            }
        }
        for(int i = 0; i < l / 3; i++){
            output(i * 3, i * 3 + 1, r);
            bool f;
            cin >> f;
            if(f == ans[l]){
                ans[i * 3] = ans[i * 3 + 1] = f;
                output(l, r, i * 3 + 2);
                cin >> ans[i * 3 + 2];
            }
            else{
                ans[i * 3 + 2] = ans[l];
                output(l, r, i * 3);
                cin >> ans[i * 3];
                ans[i * 3 + 1] = !ans[i * 3];
            }
        }
        int k = 0;
        for(int i = 0; i < n; i++) k += !ans[i];
        cout << "! " << k;
        for(int i = 0; i < n; i++){
            if(!ans[i]) cout << " " << i + 1;
        }
        cout << endl;
    }
}