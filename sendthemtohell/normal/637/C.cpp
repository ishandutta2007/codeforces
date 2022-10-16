#include <iostream>

using namespace std;
int dist(int a, int b){
    int D=0;
    while(a>0||b>0){
        if (a%10!=b%10){
            D++;
        }
        a=a/10;
        b=b/10;
    }
    return D;
}
int main()
{
    int Mas[1000];
    int n;
    cin>>n;
    int i=0,k=1,MinD=6,Dcur=0;
    while (i<n){
        cin>>Mas[i];
        i++;
    }
    i=0;
    while(i<n){
        k=i+1;
        while(k<n){
           Dcur=dist(Mas[i],Mas[k]);
           if(Dcur<MinD){
                MinD=Dcur;
           }
           k++;
        }
        i++;
    }
    if(n==1){
        cout<<6;
    }else{
        cout<<(MinD-1)/2;
    }
    return 0;
}