#include <iostream>
using namespace std;
long long coor[1001];
int main() {
	// your code goes here
	int n;
	int test1 = 0, test2 = 0, test3 = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> coor[i];
	}
	for(int i = 0; i < n; i++){
		coor[i] *= 2;
	}
	
	long long i4 = -1;
	bool four = false;
	long long s1 = coor[2] - coor[1];
	long long s2 = (coor[2] - coor[0])/2;
	long long s3 = coor[1] - coor[0];
	long long i11 = coor[0];
	long long i12 = coor[1] - s1;
	long long i21 = (coor[1] - s2);
	long long i22 = (coor[0]);
	long long i31 = coor[2] - 2 * s3;
	long long i32 = coor[0];
	if(i11 != i12){
	for(int i = 3; i < n; i++){
		if(coor[i] != s1 * i + i11 && coor[i] != s1 * i + i12){
			test1 = 1;
		}
	}
	for(int i = 3; i < n; i++){
		if(coor[i] != (s2 * i + i21) && coor[i] != (s2 * i + i22)){
			test2 = 1;
		}
	}
	for(int i = 3; i < n; i++){
		if(coor[i] != s3 * i + i31 && coor[i] != s3 * i + i32){
			test3 = 1;
		}
	}
	}
	else{
		for(int i = 3; i < n; i++){
			if(four == false){
				if(coor[i] != s1 * i + i11){
					i4 = coor[i] - i * s1;
					four = true;
				}
			}
			else{
				if(coor[i] != s1*i + i11 && coor[i]!=s1*i + i4){
					test1 = 1;
					test2 = 1;
					test3 = 1;
				}		
			}
		}
		if(four == false){
			test1 = 1;
			test2 = 1;
			test3 = 1;
		}
	}
	if(test1 == 0 || test2 == 0 || test3 == 0){
		cout << "YES";
	}
	else cout << "NO";
	
}