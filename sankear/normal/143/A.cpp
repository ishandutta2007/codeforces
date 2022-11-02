#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

int main(){
	//freopen("bad-hashing.in", "r", stdin);
	//freopen("bad-hashing.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int r1, r2, c1, c2, d1, d2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			if(i == j){
				continue;
			}
			for(int z = 1; z < 10; z++){
				if(i == z || j == z){
					continue;
				}
				for(int h = 1; h < 10; h++){
					if(i == h || j == h || z == h){
						continue;
					}
					if(i + j == r1 && z + h == r2 && i + z == c1 && j + h == c2 && i + h == d1 && j + z == d2){
						cout << i << " " << j << endl;
						cout << z << " " << h << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}