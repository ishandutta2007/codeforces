n = int(input())
BAS = input()
s = BAS.split("S")
m = 0
if len(s) > 1:
    for elem in range(len(s)-1):
        if len(s[elem]) > 0 or len(s[elem+1]) > 0:
            if m < len(s[elem] + s[elem+1]) + 1:
                m = len(s[elem] + s[elem+1]) + 1
        else:
            if m < len(s[elem] + s[elem+1]):
                m = len(s[elem] + s[elem+1])
    if m > BAS.count("G"):
        print(BAS.count("G"))
    else:
        print(m)
else:
    print(n)