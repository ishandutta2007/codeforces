#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    int numc1=0, numc2=0, numr1=0, numr2=0;
    cin >> n;
    int inp;
    for (int i = 1; i <= n; i++) {
        cout << "? " << i << " " << '1' << " " << i << " " << n << endl;
        fflush(stdout);
        cin >> inp;
        if (inp % 2 != 0) {
            if (numc1 == 0)
                numc1 = i;
            else
                numc2 = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << "? " << '1' << " " << i << " " << n << " " << i << endl;
        fflush(stdout);
        cin >> inp;
        if (inp % 2 != 0) {
            if (numr1 == 0)
                numr1 = i;
            else
                numr2 = i;
        }
    }
    //cout << numc1 << " " << numc2 << " " << numr1 << " " << numr1 << endl;
    if (numr1 != 0 && numc1 != 0) {
        cout << "? " << numc1 << " " << numr1 << " " << numc1 << " " << numr1 << endl;
        fflush(stdout);
        cin >> inp;
        if (inp % 2 == 0) {
            cout << "! " << numc1 << " " << numr2 << " " << numc2 << " " << numr1 << endl;
            return 0;
        }
        else {
            cout << "! " << numc1 << " " << numr1 << " " << numc2 << " " << numr2 << endl;
            return 0;
        }
    }
    int top, down;
    if (numc1 == 0) {
        top = n;
        down = 1;
        while (top != down) {
            cout << "? " << down << " " << numr1 << " " << (top+down)/2 << " " << numr1 << endl;
            fflush(stdout);
            cin >> inp;
            if (inp % 2 == 0)
                down = (top+down)/2+1;
            else
                top = (top + down)/2;
        }
        cout << "! " << top << " " << numr1 << " " << top << " " << numr2 << endl;
    }
    else {
        top = n;
        down = 1;
        while (top != down) {
            cout << "? " << numc1 << " " << down << " " << numc1 << " " << (top+down)/2 << endl;
            fflush(stdout);
            cin >> inp;
            if (inp % 2 == 0)
                down = (top+down)/2+1;
            else
                top = (top + down)/2;
        }
        cout << "! " << numc1 << " " << top << " " << numc2 << " " << top << endl;
    }
    return 0;
}