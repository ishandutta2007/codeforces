n = int(input())
s = input()
s2 = s[0]
for i in range(1,n):
    if(ord(s[i]) == ord("a") or ord(s[i]) == ord("e") or ord(s[i]) == ord("i") or ord(s[i]) == ord("o") or ord(s[i]) == ord("u") or ord(s[i]) == ord("y")) and (ord(s[i - 1]) == ord("a") or ord(s[i - 1]) == ord("e") or ord(s[i - 1]) == ord("i") or ord(s[i - 1]) == ord("o") or ord(s[i - 1]) == ord("u") or ord(s[i - 1]) == ord("y")) :
        sf = 1
    else:
        s2 += s[i]
print(s2)