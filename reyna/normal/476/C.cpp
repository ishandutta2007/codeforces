#include <iostream>
using namespace std;
int main(){
    long long a,b;
    cin >> a >> b;
    long long md = 1000*1000*1000+7;
    long long cnt = 0;
    long long N = ((b*(b-1))/2)%md;
    for(int i = 1; i <= a;i++){
        cnt+=((((((N%md)*b)%md)*i)%md)+N%md)%md;
        cnt%=md;
    }
    cout << cnt%md << endl;
    return 0;
}