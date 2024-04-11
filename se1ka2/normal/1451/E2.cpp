#include <iostream>
using namespace std;

int a[70000];
int b[70000];
int c[70000];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) c[i] = -1;
    int j = -1, k = -1;
    for(int i = 1; i < n; i++){
        cout << "XOR 1 " << i + 1 << endl;
        cin >> b[i];
        if(c[b[i]] >= 0){
            j = c[b[i]];
            k = i;
        }
        c[b[i]] = i;
    }
    if(j >= 0){
        cout << "AND " << j + 1 << " " << k + 1 << endl;
        cin >> a[j];
        for(int i = 0; i < n; i++){
            a[i] = a[j] ^ b[j] ^ b[i];
        }
    }
    else{
        if(c[n - 1] == 1){
            j = 2;
            k = 1;
        }
        else{
            j = 1;
            k = c[n - 1];
        }
        int d[3];
        cout << "OR 1 " << j + 1 << endl;
        cin >> d[0];
        cout << "OR " << j + 1 << " " << k + 1 << endl;
        cin >> d[1];
        d[2] = n - 1;
        for(int i = 0; i < 16; i++){
            if((b[j] >> i) & 1){
                if(((b[j] ^ b[k]) >> i) & 1){
                    if((d[2] >> i) & 1) a[0] += (1 << i);
                }
                else{
                    if(!((d[1] >> i) & 1)) a[0] += (1 << i);
                }
            }
            else{
                if(((b[j] ^ b[k]) >> i) & 1){
                    if((d[0] >> i) & 1) a[0] += (1 << i);
                }
                else{
                    if((d[0] >> i) & 1) a[0] += (1 << i);
                }
            }
        }
        for(int i = 1; i < n; i++) a[i] = a[0] ^ b[i];
    }
    cout << "!";
    for(int i = 0; i < n; i++) cout << " " << a[i];
    cout << endl;
}