s = input()
ans='NO'
mass = input().split()
for t in mass:
    for k in t:
        if k==s[0]or k==s[1]:
            ans='YES'
print(ans)