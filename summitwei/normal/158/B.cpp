#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    
    for(int i=0; i<n; i++){
        int blah;
        cin >> blah;
        if(blah == 1){
            count1++;
        } else if(blah == 2){
            count2++;
        } else if(blah == 3){
            count3++;
        } else {
            count4++;
        }
    }

    int totalCount = 0;
    totalCount += count4;
    count4 = 0;
    
    if(count1 >= count3){
        totalCount += count3;
        count1 -= count3;
        count3 = 0;
    } else {
        totalCount += count3;
        count1 = 0;
        count3 = 0;
    }

    if(count1 != 0){
        totalCount += floor(count1 / 4.0);
        count1 = count1 % 4;

        if((count1 == 1 || count1 == 2) && count2 != 0){
            totalCount++;
            count1 = 0;
            count2--;
        } else if(count1 == 3){
            totalCount++;
            count1 = 0;
        } else if(count1 != 0) {
            totalCount++;
        }
    }

    if(count2 != 0){
        totalCount += ceil(count2 / 2.0);
    }

    cout << totalCount;
}