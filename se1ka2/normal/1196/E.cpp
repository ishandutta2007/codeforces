#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int b, w;
        cin >> b >> w;
        if(b > w){
            if(b > w * 3 + 1){
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            for(int i = 0; i < w; i++) cout << 2 << " " << i * 2 + 2 << endl;
            for(int i = 0; i < w; i++) cout << 2 << " " << i * 2 + 1 << endl;
            for(int i = 0; i < min(b - w, w); i++) cout << 1 << " " << i * 2 + 2 << endl;
            for(int i = 0; i < min(b - w * 2 , w); i++) cout << 3 << " " << i * 2 + 2 << endl;
            if(b == w * 3 + 1) cout << 2 << " " << w * 2 + 1 << endl;
        }
        else{
            swap(b, w);
            if(b > w * 3 + 1){
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            for(int i = 0; i < w; i++) cout << 3 << " " << i * 2 + 2 << endl;
            for(int i = 0; i < w; i++) cout << 3 << " " << i * 2 + 1 << endl;
            for(int i = 0; i < min(b - w, w); i++) cout << 2 << " " << i * 2 + 2 << endl;
            for(int i = 0; i < min(b - w * 2 , w); i++) cout << 4 << " " << i * 2 + 2 << endl;
            if(b == w * 3 + 1) cout << 3 << " " << w * 2 + 1 << endl;
        }
    }
}