n = int(input())
s = input()
t = input()
std = [s, t]
print('YES')
st = set('abc')
fin = set('abc')
st.discard(s[0])
st.discard(t[0])
fin.discard(s[1])
fin.discard(t[1])
z = st.pop()
y = fin.pop()
if z == y:
    if st:
        z = st.pop()
    elif fin:
        y = fin.pop()
    else:
        h = set('abc') - {y}
        a, b = h.pop(), h.pop()
        if (a + b) not in std:
            print(y * n + (a + b) * n)
        else:
            print(a * n + y * n + b * n)
        exit(0)
g = (set('abc') - {y, z}).pop()
if (g + z) not in std:
    print((g + z) * n + y * n)
elif (g + g) not in std:
    print(z * n + g * n + y * n)
else:
    print((g + y) * n + z * n)