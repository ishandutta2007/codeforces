#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[200005];
        int b[200005];
        for(int i = 0; i < n; i++) cin >> b[i];
        bool f = false;
        if(!f){
            for(int i = 0; i < n; i++) a[i] = b[i];
            vector<int> ans;
            for(int i = 0; i < n - 2; i += 2){
                int j = i;
                while(j >= 0 && a[j] + a[j + 1] + a[j + 2] == 2){
                    ans.push_back(j);
                    a[j] = a[j + 1] = a[j + 2] = 0;
                    j -= 2;
                }
                if(a[i] + a[i + 1] + a[i + 2] == 1 && a[i + 2] != 1){
                    ans.push_back(i);
                    a[i] = a[i + 1] = a[i + 2] = 1;
                }
            }
            for(int i = n - 3; i >= 0; i -= 2){
                int j = i;
                while(j <= n - 2 && a[j] + a[j + 1] + a[j + 2] == 2){
                    ans.push_back(j);
                    a[j] = a[j + 1] = a[j + 2] = 0;
                    j += 2;
                }
                if(a[i] + a[i + 1] + a[i + 2] == 1 && a[i] != 1){
                    ans.push_back(i);
                    a[i] = a[i + 1] = a[i + 2] = 1;
                }
            }
            f = true;
            for(int i = 0; i < n; i++){
                if(a[i]) f = false;
            }
            if(f){
                cout << "YES" << endl;
                cout << ans.size() << endl;
                for(int i : ans) cout << i + 1 << " ";
                cout << endl;
            }
        }
        if(!f){
            for(int i = 0; i < n; i++) a[i] = b[i];
            vector<int> ans;
            for(int i = n - 3; i >= 0; i -= 2){
                int j = i;
                while(j <= n - 2 && a[j] + a[j + 1] + a[j + 2] == 2){
                    ans.push_back(j);
                    a[j] = a[j + 1] = a[j + 2] = 0;
                    j += 2;
                }
                if(a[i] + a[i + 1] + a[i + 2] == 1 && a[i] != 1){
                    ans.push_back(i);
                    a[i] = a[i + 1] = a[i + 2] = 1;
                }
            }
            for(int i = 0; i < n - 2; i += 2){
                int j = i;
                while(j >= 0 && a[j] + a[j + 1] + a[j + 2] == 2){
                    ans.push_back(j);
                    a[j] = a[j + 1] = a[j + 2] = 0;
                    j -= 2;
                }
                if(a[i] + a[i + 1] + a[i + 2] == 1 && a[i + 2] != 1){
                    ans.push_back(i);
                    a[i] = a[i + 1] = a[i + 2] = 1;
                }
            }
            f = true;
            for(int i = 0; i < n; i++){
                if(a[i]) f = false;
            }
            if(f){
                cout << "YES" << endl;
                cout << ans.size() << endl;
                for(int i : ans) cout << i + 1 << " ";
                cout << endl;
            }
        }
        if(!f) cout << "NO" << endl;
    }
}