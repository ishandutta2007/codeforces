def gcd(a, b):
	return gcd(b, a % b) if b else a

t, w, b = [int(x) for x in raw_input().split(' ')]
lcm = w * b / gcd(w, b)
minV = min(w, b)
t0 = t / lcm * minV + min(t % lcm + 1, minV) - 1
d = gcd(t0, t)
print "%d/%d" % (t0 / d, t / d)