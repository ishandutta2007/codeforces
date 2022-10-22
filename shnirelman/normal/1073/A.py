n = int(input())
s = input()
c = s[0]
for i in s:
    if(i != c):
        print("YES")
        print(c + i)
        exit()
print("NO")