s = gets.chomp.chars.map { |c| c.to_i }

s = [0, 0] + s
n = s.length

begin
	0.upto(n - 1) do |i|
		(i + 1).upto(n - 1) do |j|
			(j + 1).upto(n - 1) do |k|
				if (s[i] * 100 + s[j] * 10 + s[k]) % 8 == 0
					raise s[i].to_s + s[j].to_s + s[k].to_s
				end
			end
		end
	end
rescue Exception => x
	puts 'YES'
	ans = x.message.reverse
	while ans.length > 1 and ans[-1] == '0'
		ans.chop!
	end
	puts ans.reverse
else
	puts 'NO'
end