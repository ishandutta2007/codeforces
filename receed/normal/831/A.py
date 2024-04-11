n = int(input())
a = [int(i) for i in input().split()]
st = 0
ans = "YES"
for i in range(len(a) - 1):
    if a[i] < a[i + 1]:
        if st != 0:
            ans = 'NO'
    elif a[i] == a[i + 1]:
        if st == 0:
            st = 1
        elif st == 2:
            ans = 'NO'
    else:
        st = 2
print(ans)