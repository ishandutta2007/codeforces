#include <iostream>
using namespace std;
typedef pair<int, int> P;

int a[200005];
int d[2500005];
bool b[5000005];
P p[5000005];
int ans[200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        d[a[i]]++;
    }
    int c = 0;
    for(int j = 0; j <= 2500000; j++){
        if(d[j] >= 2) ans[c++] = j;
        if(d[j] >= 4){
            cout << "YES" << endl;
            int k = 0;
            for(int i = 0; i < n; i++){
                if(a[i] == j){
                    cout << i + 1 << " ";
                    k++;
                }
                if(k == 4){
                    cout << endl;
                    return 0;
                }
            }
        }
        d[j] = 0;
    }
    if(c >= 2){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            if(a[i] == ans[0]){
                cout << i + 1 << " ";
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(a[i] == ans[1]){
                cout << i + 1 << " ";
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(a[i] == ans[0]){
                cout << i + 1 << " ";
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(a[i] == ans[1]){
                cout << i + 1 << endl;
                break;
            }
        }
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int x = a[i] + a[j];
            if(b[x] && p[x].first != i && p[x].second != i && p[x].first != j && p[x].second != j){
                cout << "YES" << endl;
                cout << p[x].first + 1 << " " << p[x].second + 1 << " " << i + 1 << " " << j + 1 << endl;
                return 0;
            }
            b[x] = true;
            p[x] = P(i, j);
        }
    }
    cout << "NO" << endl;
}