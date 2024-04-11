def norm(s)
  s.gsub('u', 'oo').gsub('oo', 'u').gsub(/k+h/, 'h')
end

n = gets.to_i
ws = n.times.map{gets.strip}
puts ws.map{|w| norm(w)}.uniq.size