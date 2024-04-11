#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[100005];
    for(int i = 0; i < n; i++) cin >> p[i];
    int l[100005]{0}, r[100005]{0};
    for(int i = 1; i < n; i++){
        if(p[i] > p[i - 1]) l[i] = l[i - 1] + 1;
    }
    for(int i = n - 2; i >= 0; i--){
        if(p[i] > p[i + 1]) r[i] = r[i + 1] + 1;
    }
    int s = 0;
    for(int i = 0; i < n; i++){
        s = max(s, max(l[i], r[i]));
    }
    if(s % 2){
        cout << 0 << endl;
        return 0;
    }
    bool f = false;
    int c = 0;
    for(int i = 0; i < n; i++){
        if(l[i] == s) c++;
        if(r[i] == s) c++;
        if(l[i] == s && r[i] == s) f = true;
    }
    if(c > 2) f = false;
    cout << f << endl;
}