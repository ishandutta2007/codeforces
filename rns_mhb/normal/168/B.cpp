#include <iostream>
#include <cstdint>
#include <vector>
#include <array>
#include <string>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;
typedef unsigned char uch;
typedef uint64_t ui64;
typedef uint32_t ui32;
typedef uint16_t ui16;
typedef uint8_t ui8;

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

typedef string str;

int main() 
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	bool need_eol=false;
	string s;
	while (getline(cin, s))
	{
		auto ch_pos = s.find_first_not_of(' ');
		if (ch_pos != string::npos && s[ch_pos]=='#')
		{
		  	if (need_eol)
		  	{
		  		need_eol=false;
		  		cout << endl;
		  	}
		  		
			cout << s << endl;
		}
		else
		{
			s.erase(remove_if(s.begin(),s.end(),[](char c) {return c==' ';}), s.end());
			cout << s;
			
			need_eol=true;
		}
	}

	if (need_eol)
		cout << endl;

	return 0;
}