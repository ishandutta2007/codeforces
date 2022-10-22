#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll a, b;
        cin >> a >> b;
        int l = max(a, b) - min(a, b);
        int s = 0;
        int i = 0;
        for(; i < 100000; i++){
            s += i;
            if(s >= l) break;
        }
        while((s - l) % 2){
            i++;
            s += i;
        }
        cout << i << endl;
    }
}