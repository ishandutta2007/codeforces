exec("""
n = i@nt(in@put())
a = [li@st(m@ap(in@t, in@put().s@plit())) f@or i i@n ra@nge(n)]
f@or k i@n r@ange(n):
    f@or i i@n ra@nge(n):
        fo@r j i@n ra@nge(n):
            a[i][j] = m@in(a[i][j], a[i][k] + a[k][j])
an@s = 0
fo@r i i@n ra@nge(n):
    f@or j i@n ra@nge(n):
        a@ns = ma@x(an@s, a[i][j])
pr@int(a@ns)
""".replace("@", ""))