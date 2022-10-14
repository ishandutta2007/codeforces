s1, s2 = input().split()
n = int(input())
for i in range(n):
    print(s1, s2)
    t1, t2 = input().split()
    if s1 == t1:
        s1 = t2
    elif s1 == t2:
        s1 = t1
    elif s2 == t1:
        s2 = t2
    else:
        s2 = t1
print(s1, s2)