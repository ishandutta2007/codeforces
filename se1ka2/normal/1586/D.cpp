#include <iostream>
using namespace std;

int query(int n, int *a){
    cout << "?";
    for(int i = 0; i < n; i++) cout << " " << a[i];
    cout << endl;
    int k;
    cin >> k;
    k--;
    return k;
}

int main()
{
    int n;
    cin >> n;
    int a[102];
    int p[102];
    bool f = false;
    for(int c = -n + 1; c < n; c++){
        for(int i = 0; i < n - 1; i++){
            if(c < 0) a[i] = 1;
            else a[i] = c + 1;
        }
        if(c < 0) a[n - 1] = -c + 1;
        else a[n - 1] = 1;
        int k = query(n, a);
        if(k != -1){
            if(!f){
                f = true;
                if(c == 1) p[n - 1] = n;
                else p[n - 1] = n + c;
            }
            p[k] = p[n - 1] - c;
        }
    }
    cout << "!";
    for(int i = 0; i < n; i++) cout << " " << p[i];
    cout << endl;
}