import math

def solveProblem(diameter, initialLevel, waterSink, levelIncrease):
	radius = diameter / 2.0
	levelDecrease = waterSink / (math.pi * radius * radius)
	if levelIncrease > levelDecrease:
		return -1
	else:
		return initialLevel / (levelDecrease - levelIncrease)

d, h, v, e = [int(n) for n in raw_input().split()]
answer = solveProblem(d, h, v, e)
if answer == -1:
	print "NO"
else:
	print "YES"
	print answer