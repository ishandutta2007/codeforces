#include<bits/stdc++.h>
using namespace std;
int fi(string arr[],string a){
    for(int i=0;i<12;i++){
        if(arr[i]==a) return i;
    }
    return -1;
}
int main(){
    string arr[12]={"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
    string a,b,c;
    cin>>a>>b>>c;
    int d1=1;
    int i=fi(arr,a);
    
    while(arr[(i+d1)%12]!=b) d1++;
    int d2=1;
    i=(i+d1)%12;
    while(arr[(i+d2)%12]!=c) d2++;
    int d3=1;
    i=(i+d2)%12;
    while(arr[(i+d3)%12]!=a) d3++;
    if((d1==4 && d2==3) || (d2==4&&d3==3)||(d1==8&&d3==9)||(d3==8 && d2==9)||(d2==8 && d1==9)||(d3==4&&d1==3)){
        cout<<"major\n";
    }
    else if((d1==3 && d2==4) || (d2==3&&d3==4)||(d1==9&&d3==8)||(d3==9 && d2==8)||(d2==9 && d1==8)||(d3==3&&d1==4)){
      cout<<"minor\n";
    }
    else {
        cout<<"strange\n";
    }


}