#include <iostream>
#include <algorithm>

using namespace std;

class ob{
public:
    long long int num,font,cost;
    const bool operator< (const ob &a) const{
        return cost < a.cost;
    }
    };

bool tru(int i,int j,int k, ob a[]){
    return (a[k].font>a[j].font && a[k].num>a[j].num && a[j].font>a[i].font && a[j].num>a[i].num);
}

int main()
{
    long long int x;
    cin >> x;
    ob a[x];
    long long int ans = 1000000000;
    for(long long int i=0;i<x;i++){
        a[i].num=i;
    }
    for(long long int i=0;i<x;i++){
        cin >> a[i].font;
    }
    for(long long int i=0;i<x;i++){
        cin >> a[i].cost;
    }
    std :: sort(a,a+x);
//    for(long long int i=0;i<x;i++){
//        cout << a[i].cost << endl;
//    }

        for(long long int i=0;i<x;i++){
        for(long long int j=i+1;j<x;j++){
            if((a[j].font>a[i].font && a[j].num>a[i].num) || (a[j].font<a[i].font && a[j].num<a[i].num)){
                    for(long long int k=j+1;k<x;k++){
            if(tru(i,j,k,a) || tru(j,i,k,a) || tru(i,k,j,a) || tru(j,k,i,a) || tru(k,i,j,a) || tru(k,j,i,a)){
                ans = min(ans,a[i].cost+a[j].cost+a[k].cost);
                break;
            }
        }
            }
        }
    }
    if(ans != 1000000000) cout << ans << endl;
    else cout << "-1" << endl;
    return 0;
}